# New ports collection makefile for:	spambayes
# Date created:				Sat Feb 1 17:23:02 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spambayes
PORTVERSION=	1.0.a.6
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/(.)\.(.)\.(.)$/\1\2\3/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Bayesian anti-spam filter written in Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_SIZE=		yes

DOC_FILES=	HAMMIE.txt INTEGRATION.txt LICENSE.txt README.txt \
		TESTING.txt WHAT_IS_NEW.txt contrib/BULK.txt \
		contrib/muttrc contrib/procmailrc contrib/spambayes.el

post-install:
.ifndef(PORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
