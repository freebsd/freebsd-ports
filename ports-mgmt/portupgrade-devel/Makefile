# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	1.42
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.iDaemons.org/distfiles/
MASTER_SITE_SUBDIR=	knu
DISTNAME=	pkgtools-20010602

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse \
		pkg_tarup:${PORTSDIR}/misc/pkg_tarup

USE_RUBY=	yes

NO_BUILD=	yes

do-patch:
	${GREP} -Frl priviledge ${WRKSRC} | xargs ${RUBY} -i -pe 'gsub /priviledge/, "privilege"'

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/* ${PREFIX}/share/zsh/site-functions/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}/
.endif

.include <bsd.port.mk>
