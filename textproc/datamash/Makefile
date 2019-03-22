# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	datamash
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Numeric, textual, and statistical operations on text files

LICENSE=	GPLv3+

USES=		gmake
GNU_CONFIGURE=	yes

INFO=		${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e '/^examplesdir/s,$$(.*,${EXAMPLESDIR},' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
