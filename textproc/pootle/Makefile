# New ports collection makefile for:	pootle
# Date created:		14 Dec 2009
# Whom:			Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	pootle
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/translate/Pootle/${PORTVERSION}/
DISTNAME=	Pootle-${PORTVERSION}

MAINTAINER=	catone@cpan.org
COMMENT=	Pootle is a user-friendly web portal for simple translation process

BUILD_DEPENDS=	py*-django>=1.1:${PORTSDIR}/www/py-django \
		translate-toolkit>=1.6:${PORTSDIR}/textproc/translate-toolkit

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	Pootle

USE_RC_SUBR=	pootle.sh
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PORTDOCS=	ChangeLog COPYING INSTALL README wsgi.py

post-patch:
	@${MV} ${WRKSRC}/localsettings.py ${WRKSRC}/localsettings.py.sample

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !exists("${PREFIX}/etc/pootle/localsettings.py")
	@${CP} ${PREFIX}/etc/pootle/localsettings.py.sample   ${PREFIX}/etc/pootle/localsettings.py
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
