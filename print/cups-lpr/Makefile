# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups-lpr
PORTVERSION=	${CUPS_PORTVER}
PORTREVISION=	1
PORTREVISION=	${CUPS_PORTREV}
PORTEPOCH=	${CUPS_PORTEPOCH}
CATEGORIES=	print
MASTER_SITES=	${CUPS_MASTER_SITES}

MAINTAINER=	asa@gascom.ru
COMMENT=	The CUPS BSD and system V compatibility binaries (lp* commands)

USE_REINPLACE=	yes

MANLANG=	"" fr

.ifndef CUPS_OVERWRITE_BASE
PKGINSTALL=	nonexistent
PKGDEINSTALL=	nonexistent
PKGMESSAGE=	nonexistent
.endif

pre-everything::
.ifndef CUPS_OVERWRITE_BASE
	@${ECHO_MSG} "***"
	@${ECHO_MSG} "You can define CUPS_OVERWRITE_BASE=yes in your"
	@${ECHO_MSG} "make.conf to remove base system lpr tools from"
	@${ECHO_MSG} "PATH search. In this case it is recommended to"
	@${ECHO_MSG} "also define NO_LPR=yes, to not write base lpr"
	@${ECHO_MSG} "binaries during next make world"
	@${ECHO_MSG} "***"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/SILENT/d' \
		${WRKSRC}/Makedefs.in
	@${REINPLACE_CMD} -e '/LN/d' -e '/cat/d' \
		${WRKSRC}/man/Makefile ${WRKSRC}/man/fr/Makefile

post-install:
	${FIND} ${PREFIX}/man/cat* -type l -name '*.0' -delete
.ifdef CUPS_OVERWRITE_BASE
	${SH} ${PKGINSTALL} placeholder POST-INSTALL
	@${CAT} ${PKGMESSAGE}
.endif

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>
