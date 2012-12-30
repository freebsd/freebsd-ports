# Created by: ijliao
# $FreeBSD$

PORTNAME=	linkchecker
PORTVERSION=	6.6
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	LinkChecker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check HTML documents for broken links

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.5:${PORTSDIR}/www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}utidy>=0.2:${PORTSDIR}/www/py-utidy

OPTIONS_DEFINE=	GUI NLS

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	LinkChecker-${PORTVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

MAN1=	linkchecker.1
MAN5=	linkcheckerrc.5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-help>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-help \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=${QSCI2_VERSION}:${PORTSDIR}/devel/py-qt4-qscintilla2
.endif

.if ${PORT_OPTIONS:MNLS}
MANLANG=	"" de
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/nls-patch-setup.py
.else
	@${RM} ${WRKSRC}/po/*.po
.endif

.include <bsd.port.mk>
