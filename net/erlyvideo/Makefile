## New ports collection makefile for:   erlyvideo
# Date created:                         14 January 2011
# Whom:                                 Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	erlyvideo
PORTVERSION=	2.5.11
CATEGORIES=	net
MASTER_SITES=	http://host5.webstroy.ru/
DISTNAME=	${PORTNAME}-${PORTNAME}-v${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	RTMP flash streaming server written in erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		ruby:${PORTSDIR}/lang/ruby18
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes

ERLANGDIR=	${PREFIX}/lib/erlang
ERLYDIR=	${ERLANGDIR}/lib/${PORTNAME}-${PORTVERSION}
ERLYVIDEO=	ebin src include lib Emakefile
GITVERSION=	25cf0c2
FETCH_ARGS=	-pRr
DEPSLIST=	amf log4erl erlydtl erlmedia mpegts rtmp rtp rtsp
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-1cf9504
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		${WRKSRC}/src/${PORTNAME}.erl ${WRKSRC}/contrib/erlyctl
	@${REINPLACE_CMD} -e 's#"wwwroot"#"${PREFIX}/www/${PORTNAME}/wwwroot"#g' \
		${WRKSRC}/priv/${PORTNAME}.conf.sample
	@${REINPLACE_CMD} -e 's#"movies"#"/var/lib/${PORTNAME}/movies"#g' \
		${WRKSRC}/priv/${PORTNAME}.conf.sample
	@${FIND} ${WRKSRC} -type f -name .gitignore | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -type f -name "*.bak" | ${XARGS} ${RM}
	@${RMDIR} ${WRKSRC}/lib/misultin/ebin ${WRKSRC}/src/plugins

do-install:
	${MKDIR} ${ETCDIR} ${ERLYDIR} ${WWWDIR}
.for dir in /var/lib/${PORTNAME}/movies /var/lib/${PORTNAME}/plugins \
	/var/log/${PORTNAME}
	${MKDIR} ${dir}
.endfor
.for entry in ${ERLYVIDEO}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${entry} ${ERLYDIR}/)
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/reverse_mpegts ${PREFIX}/bin/reverse_mpegts
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/erlyctl ${PREFIX}/bin/erlyctl
	${INSTALL_SCRIPT} ${WRKSRC}/deps/rtmp/contrib/rtmp_bench ${PREFIX}/bin/rtmp_bench
	(cd ${WRKSRC} && ${COPYTREE_SHARE} wwwroot ${WWWDIR})
	${CP} ${WRKSRC}/priv/${PORTNAME}.conf.sample ${ETCDIR}/${PORTNAME}.conf.sample
	${CP} ${WRKSRC}/priv/log4erl.conf.debian ${ETCDIR}/log4erl.conf.sample
	${CP} ${WRKSRC}/priv/production.config.debian ${ETCDIR}/production.config.sample
	(cd ${WRKSRC} && ${COPYTREE_SHARE} snmp /var/lib/${PORTNAME})
.for dep in ${DEPSLIST}
	cd ${WRKSRC}/deps/${dep} && make DESTROOT= ERLANG_ROOT=${ERLANGDIR} \
	VERSION=${PORTVERSION} install
.endfor
.include <bsd.port.mk>
