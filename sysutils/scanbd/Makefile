PORTNAME=	scanbd
DISTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Scanner button daemon
WWW=		https://sourceforge.net/projects/scanbd/

LICENSE=	GPLv2

BUILD_DEPENDS=	sane-config:graphics/sane-backends
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libudev.so:devel/libudev-devd \
		libconfuse.so:devel/libconfuse
RUN_DEPENDS=	bash:shells/bash \
		scanimage:graphics/sane-backends

USES=	gettext-runtime gmake pkgconfig shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	sane-project/frontend
GL_PROJECT=	scanbd
GL_COMMIT=	4503640d202c06510f21848a684e221f613f324b

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-user=saned --with-group=saned

SHEBANG_GLOB=	*.script

USE_RC_SUBR=	scanbd

SUB_FILES=	scanbd

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/conf/scanbd.conf

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/scanbd.conf ${STAGEDIR}${ETCDIR}/scanbd.conf.sample
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${ETCDIR}/scripts ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/scanbd ${STAGEDIR}${PREFIX}/etc/rc.d/scanbd

.include <bsd.port.mk>
