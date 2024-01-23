PORTNAME=	clearsilver
PORTVERSION=	0.10.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.clearsilver.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, powerful, and language-neutral template system
WWW=		http://www.clearsilver.net/

USES=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-apache --disable-perl --disable-ruby \
		--disable-java --disable-csharp --disable-python

CONFLICTS_INSTALL=	csound go-cs # bin/cs

post-patch:
	@${REINPLACE_CMD} -E 's,(\$$\(PYTHON\)),CFLAGS="" \1,g' ${WRKSRC}/python/Makefile
	@${REINPLACE_CMD} -e 's|= @CFLAGS@|= @CFLAGS@ -fPIC|g' ${WRKSRC}/rules.mk.in
	@${REINPLACE_CMD} -e '/Makefile.depends:/,/^$$/s/gcc/$$(CC)/' ${WRKSRC}/rules.mk.in
	@${REINPLACE_CMD} -E 's|(PYTHON=\$$.*)|\1;PYTHON_SITE="${PYTHONPREFIX_SITELIBDIR}"|g' ${WRKSRC}/configure
	@${ECHO_CMD} "/* Dummy file */" > ${WRKSRC}/features.h
	@${ECHO_CMD} "/* Dummy file */" > ${WRKSRC}/cgi/features.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cs*

.include <bsd.port.mk>
