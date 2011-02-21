# ex:ts=8
# Ports collection makefile for:	linkchecker
# Date created:			Oct 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linkchecker
PORTVERSION=	6.4
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	LinkChecker-${PORTVERSION}

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Check HTML documents for broken links

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.5:${PORTSDIR}/www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}utidy>=0.2:${PORTSDIR}/www/py-utidy

OPTIONS=	GUI "Install GUI frontend dependencies" off

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	LinkChecker-${PORTVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

MAN1=	linkchecker.1
MAN5=	linkcheckerrc.5

.include <bsd.port.options.mk>

.if defined(WITH_GUI)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-help>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-help \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=${QSCI2_VERSION}:${PORTSDIR}/devel/py-qt4-qscintilla2
.endif

.if !defined(WITHOUT_NLS)
MANLANG=	"" de
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if !defined(WITHOUT_NLS)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/nls-patch-setup.py
.else
	@${RM} ${WRKSRC}/po/*.po
.endif

.include <bsd.port.mk>
