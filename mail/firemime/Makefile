# New ports collection makefile for:	mail/firemime
# Date created:				Sun 31 May 16:35:00 WST 2004
# Whom:					Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	firemime
PORTVERSION=	0.9.4
CATEGORIES=	mail devel
MASTER_SITES=	http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Callback-based interface for parsing MIME-encoded messages

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		mimedump.1
MAN3=		firemime_decode_body.3 firemime_get_full_header.3 firemime_get_header.3 \
		firemime_param_value.3 firemime_parse.3 firemime_strerror.3 \
		firemime_strip_comments.3 firemime_strip_markup.3 libfiremime.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

pre-configure:
	@-${RM} -r ${WRKSRC}/firemake/*.orig

post-install:
	${LN} -s libfiremime.so.0.9.4 ${PREFIX}/lib/libfiremime.so.0

.include <bsd.port.post.mk>
