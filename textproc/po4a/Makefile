# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	po4a
PORTVERSION=	0.45
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	LOCAL/garga/po4a

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Brings gettext translation tools to all kinds of docs

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Term-ReadKey>=2.30:${PORTSDIR}/devel/p5-Term-ReadKey \
		libtext-wrapi18n-perl>=0.06:${PORTSDIR}/textproc/libtext-wrapi18n-perl \
		p5-SGMLSpm>=1.03:${PORTSDIR}/textproc/p5-SGMLSpm \
		p5-Locale-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		jade>=0:${PORTSDIR}/textproc/jade \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
