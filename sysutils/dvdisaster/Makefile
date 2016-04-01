# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	dvdisaster
PORTVERSION=	0.72.6
CATEGORIES=	sysutils
MASTER_SITES=	http://dvdisaster.net/downloads/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	CD/DVD error recovery tool

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash

MAKEFILE=	GNUmakefile

USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20 cairo
GNU_CONFIGURE=	yes
CONFIGURE_LOG=	configure.log
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docsubdir="/" \
		--png-includes=${LOCALBASE}/include \
		--png-libraries=${LOCALBASE}/lib \
		--phpmountdir=${LOCALBASE}/www/${PORTNAME} \
		--localedir=${PREFIX}/share/locale \
		--buildroot=${STAGEDIR}
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_GROUP=	DEBUG
OPTIONS_GROUP_DEBUG=	EFENCE MEMDEBUG
OPTIONS_SUB=	yes

EFENCE_DESC=	Electric Fence malloc() debugger
MEMDEBUG_DESC=	Enable memory debugging

DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}

MEMDEBUG_CONFIGURE_ON=	-with-memdebug=yes

EFENCE_LIB_DEPENDS=	libefence.so.0:devel/ElectricFence
EFENCE_CONFIGURE_ON=	-with-efence=yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	-with-nls=no

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e '/REQUIRE_GCC/d' \
			${WRKSRC}/configure ${WRKSRC}/tools/configure
	${REINPLACE_CMD} -e '/dvdisaster uninstaller/,+12 d' \
			${WRKSRC}/GNUmakefile.template
	${REINPLACE_CMD} -e 's|(ctx)|(*ctx)|' \
			${WRKSRC}/md5.c
	${REINPLACE_CMD} -e 's|stdout, msg|stdout, "msg\\n"|' \
			${WRKSRC}/tools/memory.c

.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|THESE_ARE_THE_DEVEL_SOURCES;|GNUmakefile;|; \
		/install -d $$(BUILDROOT)$$(DOCSUBDIR)/,+18 d' \
			${WRKSRC}/GNUmakefile.template
.elif ${OSVERSION} > 1000000 && ${ARCH} == i386
	${REINPLACE_CMD} -e 's|THESE_ARE_THE_DEVEL_SOURCES;|GNUmakefile;|; \
		/install -m 644 README.MODIFYING/{N;p;s/.*/	install -m 644 TODO $$(BUILDROOT)$$(DOCSUBDIR)/;}; \
		/install -m 644 TODO $$(BUILDROOT)$$(DOCSUBDIR)/,+13 d' \
			${WRKSRC}/GNUmakefile.template
.endif

.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's|DOC_LOCALES = cs de en ru|DOC_LOCALES = en|; \
		s|install -m 644 CREDITS\*|install -m 644 CREDITS\.en|' \
			${WRKSRC}/GNUmakefile.template
.endif

do-configure:
	@(cd ${CONFIGURE_WRKSRC} && \
	if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="${INSTALL} -c " \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	${CONFIGURE_ENV} bash configure ${CONFIGURE_ARGS}; then \
		${ECHO_CMD} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
		(${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
		${FALSE}; \
	fi)

post-install:
.if ! ${PORT_OPTIONS:MEFENCE} || ! ${PORT_OPTIONS:MMEMDEBUG}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif

.include <bsd.port.post.mk>
