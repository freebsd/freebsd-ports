# New ports collection makefile for:    skill
# Version required:     3.7.7
# Date created:         20 Oct 1998
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $Id: Makefile,v 1.4 1998/10/28 22:48:35 steve Exp $
#

DISTNAME=	skill-3.7@P6
PKGNAME=	skill-3.7.7
CATEGORIES=	sysutils
MASTER_SITES=	ftp://fast.cs.utah.edu/pub/skill/
EXTRACT_SUFX=	_tar.Z

MAINTAINER=	jonny@jonny.eng.br

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Config
WRKSRC=			${WRKDIR}/${PKGNAME}

MAN1=		skill.1
MLINKS=		skill.1 snice.1

pre-configure:
	@chmod a+x ${WRKSRC}/Config

.include <bsd.port.mk>
