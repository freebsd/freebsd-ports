# New ports collection makefile for:   isync
# Date created:		2000-12-23
# Whom:			eivind
#
# $FreeBSD$

PORTNAME=	isync
PORTVERSION=	1.0.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags

USE_BDB=	42+
USE_GETOPT_LONG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		isync.1 mbsync.1 mdconvert.1
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PLIST_FILES=	bin/get-cert bin/isync bin/mbsync bin/mdconvert

CPPFLAGS=	-I${BDB_INCLUDE_DIR} -I${OPENSSLINC}
LDFLAGS=	-L${BDB_LIB_DIR} -L${OPENSSLLIB} -lssl -lcrypto

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
