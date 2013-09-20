# $FreeBSD$

PORTNAME=	erlyvideo
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://host5.webstroy.ru/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	RTMP flash streaming server written in erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes

ERLANGDIR=	${PREFIX}/lib/erlang
ERLYDIR=	${ERLANGDIR}/lib/${PORTNAME}-${PORTVERSION}
ERLYVIDEO=	ebin src include Emakefile
DEPSLIST=	amf log4erl erlmedia mpegts rtmp rtp rtsp ibrowse
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-deinstall

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		${WRKSRC}/src/${PORTNAME}.erl ${WRKSRC}/contrib/erlyctl \
		${WRKSRC}/deps/erlmedia/src/ems_log.erl \
		${WRKSRC}/priv/production.config.debian
	@${REINPLACE_CMD} -e 's#"wwwroot"#"${PREFIX}/www/${PORTNAME}/wwwroot"#g' \
		${WRKSRC}/priv/${PORTNAME}.conf.sample
	@${REINPLACE_CMD} -e 's#"movies"#"/var/lib/${PORTNAME}/movies"#g' \
		${WRKSRC}/priv/${PORTNAME}.conf.sample
	@${FIND} ${WRKSRC} -type f -name .gitignore -delete -or -name "*.bak" \
		-delete -or -name "*.orig" -delete 
	@${RMDIR} ${WRKSRC}/src/plugins

do-install:
	${MKDIR} ${ETCDIR} ${ERLYDIR} ${WWWDIR}
.for dir in /var/lib/${PORTNAME}/movies /var/lib/${PORTNAME}/plugins \
	/var/log/${PORTNAME} /var/cache/${PORTNAME}/licensed
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
.for dep in ${DEPSLIST}
	cd ${WRKSRC}/deps/${dep} && ${GMAKE} DESTROOT= ERLANG_ROOT=${ERLANGDIR} \
	VERSION=${PORTVERSION} install
.endfor
.include <bsd.port.mk>
