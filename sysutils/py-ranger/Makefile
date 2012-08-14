# New ports collection makefile for:	py-ranger
# Date created:		14 July 2012
# Whom:			Jin-Sih Lin <linpct@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ranger
PORTVERSION=	1.5.4
CATEGORIES=	sysutils python
MASTER_SITES=	http://git.savannah.gnu.org/cgit/ranger.git/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	linpct@gmail.com
COMMENT=	Ranger is a file manager with VI key bindings

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		ranger.1

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|; s|share/man/man|man/man|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
