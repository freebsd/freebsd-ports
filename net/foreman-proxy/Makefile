# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foreman-proxy
PORTVERSION=	1.4.1
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Foreman Smart Proxy

LICENSE=	GPLv3

RUN_DEPENDS=    rubygem-sinatra>=1.4.3:${PORTSDIR}/www/rubygem-sinatra \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json

OPTIONS_DEFINE= BMC PUPPET
BMC_DESC=	Depend on rubyipmi for BMC support
PUPPET_DESC=	Depend on Puppet

USE_GITHUB=	yes
GH_ACCOUNT=	theforeman
GH_PROJECT=	smart-proxy
GH_COMMIT= 	b3e190d
USE_RUBY=	yes
USE_RAKE=	yes
USE_RC_SUBR=	foreman-proxy
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install

FOREMAN_PROXY_USER?=	foreman_proxy
FOREMAN_PROXY_GROUP?=	foreman_proxy
FOREMAN_PROXY_LOGDIR?=	/var/log/foreman-proxy
FOREMAN_PROXY_RUNDIR?=	/var/run/foreman-proxy

USERS=		${FOREMAN_PROXY_USER}
GROUPS=		${FOREMAN_PROXY_GROUP}

SUB_FILES+=	pkg-install
SUB_LIST+=	RUBY="${RUBY}" \
		FOREMAN_PROXY_USER="${FOREMAN_PROXY_USER}" \
		FOREMAN_PROXY_GROUP="${FOREMAN_PROXY_GROUP}" \
		FOREMAN_PROXY_RUNDIR="${FOREMAN_PROXY_RUNDIR}" \
		FOREMAN_PROXY_LOGDIR="${FOREMAN_PROXY_LOGDIR}"

PLIST_SUB+=	${SUB_LIST} \
		MKDIR="${MKDIR}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBMC}
RUN_DEPENDS+=	rubygem-rubyipmi>=0.7:${PORTSDIR}/sysutils/rubygem-rubyipmi
.endif

.if ${PORT_OPTIONS:MPUPPET}
RUN_DEPENDS+=	puppet:${PORTSDIR}/sysutils/puppet
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e "s|/usr/bin/env ruby|${RUBY}|g" \
		-e "s|#{File.dirname(__FILE__)}/..|${DATADIR}|g" \
		${WRKSRC}/bin/smart-proxy
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/config/settings.yml.example

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${LN} -s ${PREFIX}/etc/foreman-proxy ${STAGEDIR}${DATADIR}/config
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/smart-proxy \
		${STAGEDIR}${PREFIX}/sbin/smart-proxy
.for file in Rakefile config.ru lib public views
	@${CP} -r ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/config/settings.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.yml.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.yml)
	@${INSTALL_DATA} ${WRKSRC}/config/settings.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.yml
.endif

post-install:
	@${MKDIR} -m 0700 ${STAGEDIR}${FOREMAN_PROXY_LOGDIR} \
		${STAGEDIR}${FOREMAN_PROXY_RUNDIR}
	@${SH} ${PKGINSTALL} STAGEDIR=${STAGEDIR}

.include <bsd.port.post.mk>
