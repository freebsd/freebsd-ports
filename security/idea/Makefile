# New ports collection makefile for:   idea
# Date created:		4 September 2004
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	idea
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.funet.fi/pub/org/CERT/ftp.cert.dfn.de/pub/tools/crypt/idea/ \
		http://www.de-moliner.ch/richard/downloads/ \
		http://ftp.at.linuxfromscratch.org/infosys/security/dfn/tools/crypt/idea/
DISTNAME=	${PORTNAME}.V${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A command line idea encryption and decryption utility

RESTRICTED=	"Crypto; IDEA is a patented algorithm that requires proper licensing"

WRKSRC=		${WRKDIR}/${PORTNAME}

MANL=		idea.l
MANCOMPRESSED=	no

.if !defined(MAKE_IDEA) || ${MAKE_IDEA} == "no" || ${MAKE_IDEA} == "NO"
IGNORE=		"you chose not to use idea related code"
.endif

do-build:
	${CC} ${WRKSRC}/idea.c ${WRKSRC}/idea_cmd.c ${CFLAGS} -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_MAN} ${WRKSRC}/manl/idea.l ${PREFIX}/man/manl
	${INSTALL_PROGRAM} -m 0555 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Examples ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/byte_ord.ps ${WRKSRC}/idea_cmd.txt ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
