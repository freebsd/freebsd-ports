# New ports collection makefile for:    skill
# Version required:     3.7.5
# Date created:         04 Jun 1997
# Whom:                 Joao Carlos Mendes Luis <jonny@mailhost.coppe.ufrj.br>
#
# $Id: Makefile,v 1.1.1.1 1997/06/05 17:03:24 obrien Exp $
#

DISTNAME=       skill-3.7@P4
PKGNAME=	skill-3.7.5
CATEGORIES=	sysutils
MASTER_SITES=   ftp://jaguar.cs.utah.edu/pub/skill/
EXTRACT_SUFX=	_tar.Z

MAINTAINER=	jonny@coppe.ufrj.br

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Config
WRKSRC=			${WRKDIR}/${PKGNAME}

MAN1=		skill.1

# Bugs: skill.1 and snice.1 are hard links.  When compressed they
# are changed to independent files.  I'd like to change this...

pre-configure:
	@chmod a+x ${WRKSRC}/Config

post-install:
	@ln -sf ${PREFIX}/man/man1/skill.1.gz ${PREFIX}/man/man1/snice.1.gz

.include <bsd.port.mk>
