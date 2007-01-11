# New ports collection makefile for:    referrercop
# Date created:        21 June 2005
# Whom:                Ryan Grove <ryan@wonko.com>
#
# $FreeBSD$
#

PORTNAME=	referrercop
PORTVERSION=	1.1.0
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://wonko.com/files/

MAINTAINER=	ryan@wonko.com
COMMENT=	Filters referrer spam from Apache logs and AWStats data files

NO_BUILD=		yes
USE_RUBY=		yes
USE_RUBY_FEATURES=	fileutils optparse ruby18

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/referrercop ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/blacklist.refcop ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/whitelist.refcop.sample ${DATADIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

	${MKDIR} ${DOCSDIR}/rdoc
	cd ${WRKSRC}/doc; ${FIND} . \
		| ${CPIO} -pdm -R root:wheel ${DOCSDIR}/rdoc
.endif

.include <bsd.port.post.mk>
