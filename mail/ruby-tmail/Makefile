# New ports collection makefile for:	Ruby-TMail
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tmail
PORTVERSION=	0.10.5
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.loveruby.net/archive/%SUBDIR%/ \
		http://www.ruby-lang.org/~knu/backup/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-all
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	racc-runtime

CONFIGURE_ARGS=	--with=tmail

WRKDIR_TMAIL=	${WRKSRC}/packages/tmail

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKDIR_TMAIL}/sample/ ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${CP} -R ${WRKDIR_TMAIL}/Incompatibilities ${WRKDIR_TMAIL}/README.en ${WRKDIR_TMAIL}/doc.en/* ${RUBY_DOCDIR}/${PORTNAME}/
	${CP} -R ${WRKDIR_TMAIL}/Incompatibilities.ja ${WRKDIR_TMAIL}/README.ja ${WRKDIR_TMAIL}/doc.ja/* ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endif

.include <bsd.port.mk>
