PORTNAME=	XML-Parser
PORTVERSION=	2.46
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension interface to James Clark's XML parser, expat

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	EXPATINCPATH=${LOCALBASE}/include EXPATLIBPATH=${LOCALBASE}/lib

CONV_ENC=	${PERL} -e '$$e=shift @ARGV; undef $$/; $$_=<>; substr($$_,4,40)=pack("a40","$$e"); print'

OPTIONS_RADIO=	EUCJP SJIS
OPTIONS_RADIO_EUCJP=	EUCJP_JISX0221 EUCJP_UNICODE
OPTIONS_RADIO_SJIS=	SJIS_CP932 SJIS_JDK117 SJIS_JISX0221 SJIS_UNICODE
OPTIONS_SUB=	yes
EUCJP_JISX0221_DESC=	Install euc-jp.enc (generated from x-euc-jp-jisx0221.enc)
EUCJP_UNICODE_DESC=	Install euc-jp.enc (generated from x-euc-jp-unicode.enc)
SJIS_CP932_DESC=	Install shift_jis.enc (generated from x-sjis-cp932.enc)
SJIS_JDK117_DESC=	Install shift_jis.enc (generated from x-sjis-jdk117.enc)
SJIS_JISX0221_DESC=	Install shift_jis.enc (generated from x-sjis-jisx0221.enc)
SJIS_UNICODE_DESC=	Install shift_jis.enc (generated from x-sjis-unicode.enc)

EUCJP_JISX0221_USE=	PERL5=patch
EUCJP_UNICODE_USE=	PERL5=patch
SJIS_CP932_USE=		PERL5=patch
SJIS_JDK117_USE=	PERL5=patch
SJIS_JISX0221_USE=	PERL5=patch
SJIS_UNICODE_USE=	PERL5=patch

pre-patch-EUCJP_JISX0221-on:
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} euc-jp x-euc-jp-jisx0221.enc > euc-jp.enc
	@${ECHO_CMD} Parser/Encodings/euc-jp.enc >> ${WRKSRC}/MANIFEST

pre-patch-EUCJP_UNICODE-on:
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} euc-jp x-euc-jp-unicode.enc > euc-jp.enc
	@${ECHO_CMD} Parser/Encodings/euc-jp.enc >> ${WRKSRC}/MANIFEST

pre-patch-SJIS_CP932-on:
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} shift_jis x-sjis-cp932.enc > shift_jis.enc
	@${ECHO_CMD} Parser/Encodings/shift_jis.enc >> ${WRKSRC}/MANIFEST

pre-patch-SJIS_JDK117-on:
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} shift_jis x-sjis-jdk117.enc > shift_jis.enc
	@${ECHO_CMD} Parser/Encodings/shift_jis.enc >> ${WRKSRC}/MANIFEST

pre-patch-SJIS_JISX0221-on:
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} shift_jis x-sjis-jisx0221.enc > shift_jis.enc
	@${ECHO_CMD} Parser/Encodings/shift_jis.enc >> ${WRKSRC}/MANIFEST

pre-patch-SJIS_UNICODE-on:
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} shift_jis x-sjis-unicode.enc > shift_jis.enc
	@${ECHO_CMD} Parser/Encodings/shift_jis.enc >> ${WRKSRC}/MANIFEST

post-patch:
	@${CP} ${FILESDIR}/*.enc ${WRKSRC}/Parser/Encodings/
.for e in 1 6 10 11 13 14 15
	@${ECHO_CMD} Parser/Encodings/iso-8859-${e}.enc >> ${WRKSRC}/MANIFEST
.endfor

post-configure:
	@${PERL} -i -pe 's|^(CC = ).*|$$1 ${CC}|;' -e 's|^(CCFLAGS = ).*|$$1 ${CFLAGS}|' ${WRKSRC}/Expat/Makefile

pre-build:
	@cd ${WRKDIR} && ${PERL} ${FILESDIR}/check_nfs.pl 2>/dev/null || (${ECHO_MSG} "===>  lockf in \$$TMPDIR required"; ${FALSE})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XML/Parser/Expat/Expat.so

# maintainer section:
# require: p5-XML-Encoding

build-encodings:
.for e in 1 6 10 11 13 14 15
	${MAKE_CMD} -C ${.CURDIR}/../p5-XML-Encoding patch
	cd `${MAKE_CMD} -C ${.CURDIR}/../p5-XML-Encoding -V WRKSRC` && ${PERL} bin/compile_encoding -o ${FILESDIR}/iso-8859-${e}.enc maps/iso-8859-${e}.xml
	${MAKE_CMD} -C ${.CURDIR}/../p5-XML-Encoding do-clean
.endfor

.include <bsd.port.mk>
