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
PORTREVISION=	${CUPS_PORTREV}
PORTEPOCH=	${CUPS_PORTEPOCH}
CATEGORIES=	print
MASTER_SITES=	${CUPS_MASTER_SITES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The CUPS BSD and system V compatibility binaries (lp* commands)

USE_REINPLACE=	yes

MANLANG=	"" fr

post-patch:
	@${REINPLACE_CMD} -e '/SILENT/d' \
		${WRKSRC}/Makedefs.in
	@${REINPLACE_CMD} -e '/LN/d' \
		${WRKSRC}/man/Makefile ${WRKSRC}/man/fr/Makefile

post-install:
	${FIND} ${PREFIX}/man/cat* -type l -name '*.0' -delete
	${FIND} ${PREFIX}/man/fr/cat* -type l -name '*.0' -delete


.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>

#EOF
