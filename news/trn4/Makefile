# New ports collection makefile for:	trn
# Version required:	4.0-test64
# Date created:		21 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.14 1998/05/01 07:52:00 asami Exp $
#

DISTNAME=	trn4-test64
PKGNAME=	trn-4.0b64
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.clari.net/private/trn/ \
		ftp://ftp.uu.net/private/trn/

MAINTAINER=	mph@freebsd.org

NO_LATEST_LINK=	yes
NO_PACKAGE=	"Too many questions"
IS_INTERACTIVE=	yes
MAN1=		trn.1 Pnews.1 Rnmail.1

pre-configure:
	@echo "===>  Running pre-configure target for ${DISTNAME}"
	@${SED} -e "s:__CC__:$(CC):" -e "s:__CFLAGS__:$(CFLAGS):" \
		-e "s:/PREFIX:$(PREFIX):"  ${SCRIPTDIR}/preconf > \
		${WRKDIR}/preconf.new
	@sh ${WRKDIR}/preconf.new ${PORTSDIR} ${.CURDIR} ${WRKSRC}

.include <bsd.port.mk>
