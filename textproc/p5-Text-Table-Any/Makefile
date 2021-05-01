# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Text-Table-Any
PORTVERSION=	0.104
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate text table using one of several backends

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Text-Table-Sprintf>=0:textproc/p5-Text-Table-Sprintf

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-Term-TablePrint>=0:devel/p5-Term-TablePrint \
				p5-Text-ANSITable>=0:textproc/p5-Text-ANSITable \
				p5-Text-ASCIITable>=0:textproc/p5-Text-ASCIITable \
				p5-Text-FormatTable>=0:textproc/p5-Text-FormatTable \
				p5-Text-MarkdownTable>=0:textproc/p5-Text-MarkdownTable \
				p5-Text-Table>=0:textproc/p5-Text-Table \
				p5-Text-Table-ASV>=0:textproc/p5-Text-Table-ASV \
				p5-Text-Table-CSV>=0.022:textproc/p5-Text-Table-CSV \
				p5-Text-Table-HTML>=0:textproc/p5-Text-Table-HTML \
				p5-Text-Table-HTML-DataTables>=0:textproc/p5-Text-Table-HTML-DataTables \
				p5-Text-Table-LTSV>=0:textproc/p5-Text-Table-LTSV \
				p5-Text-Table-Manifold>=0:textproc/p5-Text-Table-Manifold \
				p5-Text-Table-More>=0:textproc/p5-Text-Table-More \
				p5-Text-Table-Org>=0:textproc/p5-Text-Table-Org \
				p5-Text-Table-Paragraph>=0:textproc/p5-Text-Table-Paragraph \
				p5-Text-Table-TSV>=0:textproc/p5-Text-Table-TSV \
				p5-Text-Table-Tiny>=0:textproc/p5-Text-Table-Tiny \
				p5-Text-Table-TickitWidget>=0:textproc/p5-Text-Table-TickitWidget \
				p5-Text-Table-TinyBorderStyle>=0:textproc/p5-Text-Table-TinyBorderStyle \
				p5-Text-Table-TinyColor>=0:textproc/p5-Text-Table-TinyColor \
				p5-Text-Table-TinyColorWide>=0:textproc/p5-Text-Table-TinyColorWide \
				p5-Text-Table-TinyWide>=0:textproc/p5-Text-Table-TinyWide \
				p5-Text-Table-XLSX>=0:textproc/p5-Text-Table-XLSX \
				p5-Text-TabularDisplay>=0:textproc/p5-Text-TabularDisplay \
				p5-Text-UnicodeBox>=0:textproc/p5-Text-UnicodeBox
RECOMMENDED_RUN_DEPENDS=	p5-Term-TablePrint>=0:devel/p5-Term-TablePrint \
				p5-Text-ANSITable>=0:textproc/p5-Text-ANSITable \
				p5-Text-ASCIITable>=0:textproc/p5-Text-ASCIITable \
				p5-Text-FormatTable>=0:textproc/p5-Text-FormatTable \
				p5-Text-MarkdownTable>=0:textproc/p5-Text-MarkdownTable \
				p5-Text-Table>=0:textproc/p5-Text-Table \
				p5-Text-Table-ASV>=0:textproc/p5-Text-Table-ASV \
				p5-Text-Table-CSV>=0.022:textproc/p5-Text-Table-CSV \
				p5-Text-Table-HTML>=0:textproc/p5-Text-Table-HTML \
				p5-Text-Table-HTML-DataTables>=0:textproc/p5-Text-Table-HTML-DataTables \
				p5-Text-Table-LTSV>=0:textproc/p5-Text-Table-LTSV \
				p5-Text-Table-Manifold>=0:textproc/p5-Text-Table-Manifold \
				p5-Text-Table-More>=0:textproc/p5-Text-Table-More \
				p5-Text-Table-Org>=0:textproc/p5-Text-Table-Org \
				p5-Text-Table-Paragraph>=0:textproc/p5-Text-Table-Paragraph \
				p5-Text-Table-TSV>=0:textproc/p5-Text-Table-TSV \
				p5-Text-Table-TickitWidget>=0:textproc/p5-Text-Table-TickitWidget \
				p5-Text-Table-Tiny>=0:textproc/p5-Text-Table-Tiny \
				p5-Text-Table-TinyBorderStyle>=0:textproc/p5-Text-Table-TinyBorderStyle \
				p5-Text-Table-TinyColor>=0:textproc/p5-Text-Table-TinyColor \
				p5-Text-Table-TinyColorWide>=0:textproc/p5-Text-Table-TinyColorWide \
				p5-Text-Table-TinyWide>=0:textproc/p5-Text-Table-TinyWide \
				p5-Text-Table-XLSX>=0:textproc/p5-Text-Table-XLSX \
				p5-Text-TabularDisplay>=0:textproc/p5-Text-TabularDisplay \
				p5-Text-UnicodeBox>=0:textproc/p5-Text-UnicodeBox

.include <bsd.port.mk>
