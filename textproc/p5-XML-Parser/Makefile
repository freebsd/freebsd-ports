# New ports collection makefile for:	XML::Parser
# Date created:		15 Nov 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser
PORTVERSION=	2.36
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension interface to James Clark's XML parser, expat

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	EXPATLIBPATH=${LOCALBASE}/lib EXPATINCPATH=${LOCALBASE}/include

MAN3=		XML::Parser.3 XML::Parser::Expat.3 \
		XML::Parser::Style::Debug.3 \
		XML::Parser::Style::Objects.3 \
		XML::Parser::Style::Stream.3 \
		XML::Parser::Style::Subs.3 \
		XML::Parser::Style::Tree.3
PLIST_SUB=	EUCJP=${EUCJP} SJIS=${SJIS}

# XMLPARSER_EUCJP=	x-euc-jp-(jisx0221|unicode)
# XMLPARSER_SJIS=	x-sjis-(cp932|jdk117|jisx0221|unicode)
CONV_ENC=	${PERL} -e '$$e=shift @ARGV; undef $$/; $$_=<>; substr($$_,4,40)=pack("a40","$$e"); print'
.if !defined(XMLPARSER_EUCJP)
EUCJP=		"@comment "
.endif
.if !defined(XMLPARSER_SJIS)
SJIS=		"@comment "
.endif

post-patch:
.if defined(XMLPARSER_EUCJP)
	@cd ${WRKSRC}/Parser/Encodings; \
		${CONV_ENC} euc-jp ${XMLPARSER_EUCJP}.enc > euc-jp.enc
	@${ECHO_CMD} Parser/Encodings/euc-jp.enc >> ${WRKSRC}/MANIFEST
.endif
.if defined(XMLPARSER_SJIS)
	@cd ${WRKSRC}/Parser/Encodings; \
		${CONV_ENC} shift_jis ${XMLPARSER_SJIS}.enc > shift_jis.enc
	@${ECHO_CMD} Parser/Encodings/Shift_JIS.enc >> ${WRKSRC}/MANIFEST
.endif
	@${CP} ${FILESDIR}/*.enc ${WRKSRC}/Parser/Encodings/
.for e in 1 6 10 11 13 14 15
	@${ECHO_CMD} Parser/Encodings/iso-8859-${e}.enc >> ${WRKSRC}/MANIFEST
.endfor

post-configure:
	@${PERL} -i -pe 's|^(CC = ).*|$$1 ${CC}|;' \
		-e 's|^(CCFLAGS = ).*|$$1 ${CFLAGS}|' ${WRKSRC}/Expat/Makefile

XE=	${.CURDIR}/../p5-XML-Encoding
extract-encodings:
	@cd ${XE}; \
	${MAKE} patch; \
	${CHMOD} og+rX `make -VWRKSRC`

build-encodings:
.for e in 1 6 10 11 13 14 15
	@cd `cd ${XE}; ${MAKE} -VWRKSRC`; \
	compile_encoding -o ${FILESDIR}/iso-8859-${e}.enc maps/iso-8859-${e}.xml
.endfor

.include <bsd.port.mk>
