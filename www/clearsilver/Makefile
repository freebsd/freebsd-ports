# Created by: thinker <thinker@branda.to>
# $FreeBSD$

PORTNAME=	clearsilver
PORTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.clearsilver.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, powerful, and language-neutral template system

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-apache --disable-perl --disable-ruby \
		--disable-java --disable-csharp

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
USES+=		python:2.7
PLIST_SUB+=	PYTHON=""
PKGNAMESUFFIX=	-python
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@# Remove CFLAGS when building the python module, pydistfile is used
	@# and will do the right thing.
	@${REINPLACE_CMD} -E 's,(\$$\(PYTHON\)),CFLAGS="" \1,g' ${WRKSRC}/python/Makefile
	@# insert -fPIC into CFLAGS to fix non-i386 builds
	@${REINPLACE_CMD} -e 's|= @CFLAGS@|= @CFLAGS@ -fPIC|g' ${WRKSRC}/rules.mk.in
	@# don't hardcode gcc for make depend
	@${REINPLACE_CMD} -e '/Makefile.depends:/,/^$$/s/gcc/$$(CC)/' ${WRKSRC}/rules.mk.in
	@# Set PYTHON_SITE
	@${REINPLACE_CMD} -E 's|(PYTHON=\$$.*)|\1;PYTHON_SITE="${PYTHONPREFIX_SITELIBDIR}"|g' ${WRKSRC}/configure
	@# Create the features.h files that are needed to build
	@${ECHO_CMD} "/* Dummy file */" > ${WRKSRC}/features.h
	@${ECHO_CMD} "/* Dummy file */" > ${WRKSRC}/cgi/features.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cs*

.include <bsd.port.mk>
