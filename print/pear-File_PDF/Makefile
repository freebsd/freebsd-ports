# Ports collection makefile for:  pear-File_PDF
# Date created:			  11 October 2006
# Whom:				  Anish Mistry <amistry@am-productions.biz>
#
# $FreeBSD$
#

PORTNAME=	File_PDF
PORTVERSION=	0.3.2
CATEGORIES=	print pear

MAINTAINER=	amistry@am-productions.biz
COMMENT=	PEAR class to generate PDFs

CATEGORY=	File
FILES=		PDF.php PDF/fonts/courier.php PDF/fonts/helvetica.php \
		PDF/fonts/helveticab.php PDF/fonts/helveticabi.php \
		PDF/fonts/helveticai.php PDF/fonts/symbol.php \
		PDF/fonts/times.php PDF/fonts/timesb.php PDF/fonts/timesbi.php \
		PDF/fonts/timesi.php PDF/fonts/zapfdingbats.php
TESTS=		auto_break.phpt factory.phpt hello_world.phpt horde-power1.png \
		links.phpt locale_floats.phpt pear12310.phpt text_color.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
