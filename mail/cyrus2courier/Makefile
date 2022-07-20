PORTNAME=	cyrus2courier
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.madness.at/~mad/projects/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cyrus-IMAP to Maildir++ conversion utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz

ALL_TARGET=	build

PLIST_FILES=	bin/cyrus2courier

post-patch:
	@${REINPLACE_CMD} '/^CFLAGS*/d; /^LDFLAGS*/d; /^CC*/d' \
		${WRKSRC}/src/Makefile.FreeBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
