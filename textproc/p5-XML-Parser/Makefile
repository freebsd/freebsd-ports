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

PLIST_SUB=	EUCJP=${EUCJP} SJIS=${SJIS}

CONV_ENC=	${PERL} -e '$$e=shift @ARGV; undef $$/; $$_=<>; substr($$_,4,40)=pack("a40","$$e"); print'

# XMLPARSER_EUCJP=	x-euc-jp-(jisx0221|unicode)
# XMLPARSER_SJIS=	x-sjis-(cp932|jdk117|jisx0221|unicode)
.if !defined(XMLPARSER_EUCJP)
EUCJP=		"@comment "
.endif
.if !defined(XMLPARSER_SJIS)
SJIS=		"@comment "
.endif
.if defined(XMLPARSER_EUCJP) || defined(XMLPARSER_SJIS)
USE_PERL5+=	patch
.endif

post-patch:
.if defined(XMLPARSER_EUCJP)
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} euc-jp ${XMLPARSER_EUCJP}.enc > euc-jp.enc
	@${ECHO_CMD} Parser/Encodings/euc-jp.enc >> ${WRKSRC}/MANIFEST
.endif
.if defined(XMLPARSER_SJIS)
	@cd ${WRKSRC}/Parser/Encodings && ${CONV_ENC} shift_jis ${XMLPARSER_SJIS}.enc > shift_jis.enc
	@${ECHO_CMD} Parser/Encodings/shift_jis.enc >> ${WRKSRC}/MANIFEST
.endif
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
