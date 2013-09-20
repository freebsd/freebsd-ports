# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	stow
PORTVERSION=	2.2.0
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	5u623l20@gmail.com
COMMENT=	GNU version of Carnegie Mellon's "Depot" program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	p5-Test-Output>0:${PORTSDIR}/devel/p5-Test-Output

USE_BZIP2=	yes
USES=		perl5
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

NO_STAGE=	yes
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
