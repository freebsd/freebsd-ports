# New ports collection makefile for:	svnmailer
# Date created:		2005-08-30
# Whom:			Andrej Zverev <az@inec.ru>
#
# $FreeBSD$
#

PORTNAME=	svnmailer
DISTVERSION=	1.1.0-dev-r1373
PORTREVISION=	4
CATEGORIES=	mail python
MASTER_SITES=	http://storage.perlig.de/${PORTNAME}/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A tool to post subversion repository commit information

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libsvn/__init__.py:${PORTSDIR}/devel/py-subversion
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	YES
USE_PYTHON=		2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

MAN1=		svn-mailer.1

.include <bsd.port.pre.mk>

pre-patch:
.if ${PYTHON_REL} >= 250
EXTRA_PATCHES=	${FILESDIR}/py25-src-lib-svnmailer-notifier-_base.py
.endif

.if defined(NOPORTDOCS)
PYDISTUTILS_INSTALLARGS+=	--no-install-docs
.else
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "1s|^.*|#!${PYTHON_CMD}|" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "1s|^.*|#!${PYTHON_CMD}|" ${WRKSRC}/src/svn-mailer

.include <bsd.port.post.mk>
