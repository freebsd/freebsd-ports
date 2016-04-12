# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Spreadsheet-XLSX
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMOW
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-withoutworldwriteables

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl extension for reading MS Excel 2007 files

BUILD_DEPENDS=	p5-Spreadsheet-ParseExcel>0:textproc/p5-Spreadsheet-ParseExcel \
		p5-Archive-Zip>0:archivers/p5-Archive-Zip
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
