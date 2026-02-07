PORTNAME=	biber
# https://sourceforge.net/projects/biblatex-biber/files/biblatex-biber/development/documentation/biber.pdf/download
# Keep this in-sync with biblatex.sty (currently at 3.20).
DISTVERSIONPREFIX=	v
DISTVERSION=	2.21
PORTEPOCH=	2
CATEGORIES=	print perl5
PKGNAMEPREFIX=	latex-
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	BibTeX replacement for users of BibLaTeX
WWW=		https://biblatex-biber.sourceforge.net/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

__DEPENDS=	\
		ja-p5-Encode-EUCJPASCII>0:japanese/p5-Encode-EUCJPASCII \
		p5-Business-ISBN>0:misc/p5-Business-ISBN \
		p5-Business-ISMN>0:misc/p5-Business-ISMN \
		p5-Business-ISSN>0:misc/p5-Business-ISSN \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Config-AutoConf>0:devel/p5-Config-AutoConf \
		p5-Data-Compare>0:devel/p5-Data-Compare \
		p5-Data-Dump>0:devel/p5-Data-Dump \
		p5-Data-Uniqid>0:devel/p5-Data-Uniqid \
		p5-DateTime-Calendar-Julian>=0:devel/p5-DateTime-Calendar-Julian \
		p5-DateTime-Format-Builder>=0:devel/p5-DateTime-Format-Builder \
		p5-Encode-HanExtra>0:chinese/p5-Encode-HanExtra \
		p5-Encode-JIS2K>0:converters/p5-Encode-JIS2K \
		p5-Encode-Locale>0:converters/p5-Encode-Locale \
		p5-ExtUtils-LibBuilder>0:devel/p5-ExtUtils-LibBuilder \
		p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-IO-String>0:devel/p5-IO-String \
		p5-IPC-Run3>0:devel/p5-IPC-Run3 \
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https \
		p5-Lingua-Translit>0:devel/p5-Lingua-Translit \
		p5-List-AllUtils>0:devel/p5-List-AllUtils \
		p5-List-MoreUtils-XS>0:lang/p5-List-MoreUtils-XS \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Log-Log4perl>0:devel/p5-Log-Log4perl \
		p5-Mozilla-CA>0:www/p5-Mozilla-CA \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent \
		p5-PerlIO-utf8_strict>0:devel/p5-PerlIO-utf8_strict \
		p5-Regexp-Common>0:textproc/p5-Regexp-Common \
		p5-Sort-Key>=0:devel/p5-Sort-Key \
		p5-Text-BibTeX>0:textproc/p5-Text-BibTeX \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Text-CSV_XS>0:textproc/p5-Text-CSV_XS \
		p5-Text-Roman>0:textproc/p5-Text-Roman \
		p5-URI>0:net/p5-URI \
		p5-Unicode-LineBreak>0:textproc/p5-Unicode-LineBreak \
		p5-XML-LibXML-Simple>0:textproc/p5-XML-LibXML-Simple \
		p5-XML-LibXML>0:textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>0:textproc/p5-XML-LibXSLT \
		p5-XML-Writer>0:textproc/p5-XML-Writer \
		p5-autovivification>0:devel/p5-autovivification \
		p5-libwww>0:www/p5-libwww
BUILD_DEPENDS=	${__DEPENDS}
RUN_DEPENDS=	${__DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0.680:devel/p5-Test-Differences

USES=		perl5 tex
USE_GITHUB=	yes
GH_ACCOUNT=	plk
USE_PERL5=	modbuild
USE_TEX=	texmf

# All tests successful. Files=51, Tests=1274. Result: PASS
TEST_ENV+=	BIBER_DEV_TESTS=1

NO_ARCH=	yes

.include <bsd.port.mk>
