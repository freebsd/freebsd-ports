# $FreeBSD$

PORTNAME=	tlsdate
PORTVERSION=	0.0.7
CATEGORIES=	sysutils
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Secure parasitic rdate replacement

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ioerror
# Technically tlsdate 0.0.7 is 004f6f6, but a couple of follow-up
# commits are required to fix the build on FreeBSD.
GH_COMMIT=	44fa3b7
GH_TAGNAME=	${GH_COMMIT}

USE_AUTOTOOLS=	autoconf aclocal automake libtool
USES=		pkgconfig

OPTIONS_DEFINE=	DOCS

post-patch:
# Required for FreeBSD 8.4
	@${REINPLACE_CMD} -e 's@AC_MSG_ERROR(\[M@AC_MSG_WARN([M@' ${WRKSRC}/configure.ac

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

regression-test: build
	@cd ${WRKSRC} && make test

.include <bsd.port.mk>
