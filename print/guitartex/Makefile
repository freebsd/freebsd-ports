# ex:ts=8
# New ports collection makefile for:	GuitarTeX
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	guitartex
PORTVERSION=	2.4.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	GuitarTeX converts the Chord format into "normal" LaTeX format

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk \
		latex:${PORTSDIR}/print/latex

USE_REINPLACE=	yes
USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,\"\(.*\.gif\)\",\"${DATADIR}/\1\",g" ${WRKSRC}/guitartex

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/guitartex ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.gif ${WRKSRC}/*.ps ${DATADIR}

.include <bsd.port.mk>
