# ex:ts=8
# Ports collection makefile for:  stow
# Date created:			  6 June 2000
# Whom:				  Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	stow
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU version of Carnegie Mellon's "Depot" program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	p5-Test-Output>0:${PORTSDIR}/devel/p5-Test-Output

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}
INSTALL_TARGET=	install-exec-am install-dist_pmstowDATA install-info-am \
		install-man install-pmDATA

MAN8=		stow.8
INFO=		stow
PORTDOCS=	*
PLIST_FILES=	bin/chkstow \
		bin/stow \
		%%SITE_PERL%%/Stow.pm \
		%%SITE_PERL%%/Stow/Util.pm
PLIST_DIRS=	%%SITE_PERL%%/Stow

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in ChangeLog.OLD manual-single.html manual.pdf version.texi
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} manual-split ${DOCSDIR})
.endif

.include <bsd.port.mk>
