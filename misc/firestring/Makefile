# New ports collection makefile for:	firestring
# Date created:		Mon 13 May 14:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	firestring
PORTVERSION=	0.1.23
CATEGORIES=	misc net devel
MASTER_SITES=	http://ares.penguinhosting.net/~ian/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	-${PORTVERSION}.tar.gz

MAINTAINER=	dean@odyssey.apana.org.au

HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		firestring_chomp.3 firestring_chug.3 \
		firestring_concat.3 firestring_conf_add.3 \
		firestring_conf_find.3 firestring_conf_find_next.3 \
		firestring_conf_free.3 firestring_conf_parse.3 \
		firestring_conf_parse_next.3 firestring_estr_0.3 \
		firestring_estr_alloc.3 firestring_estr_base64_decode.3 \
		firestring_estr_base64_encode.3 firestring_estr_ends.3 \
		firestring_estr_estrcasecmp.3 firestring_estr_estrcat.3 \
		firestring_estr_estrcmp.3 firestring_estr_estrcpy.3 \
		firestring_estr_estristr.3 \
		firestring_estr_estrncasecmp.3 firestring_estr_estrstr.3 \
		firestring_estr_expand.3 firestring_estr_free.3 \
		firestring_estr_read.3 firestring_estr_sprintf.3 \
		firestring_estr_starts.3 firestring_estr_strcasecmp.3 \
		firestring_estr_strcat.3 firestring_estr_strchr.3 \
		firestring_estr_strcmp.3 firestring_estr_strcpy.3 \
		firestring_estr_stristr.3 firestring_estr_strstr.3 \
		firestring_estr_xml_decode.3 \
		firestring_estr_xml_encode.3 firestring_hextoi.3 \
		firestring_malloc.3 firestring_realloc.3 \
		firestring_snprintf.3 firestring_strcasecmp.3 \
		firestring_strdup.3 firestring_strncasecmp.3 \
		firestring_strncat.3 firestring_strncpy.3 \
		libfirestring.3

post-install:
	@cd ${PREFIX}/lib; ${MV} libfirestring.so libfirestring.so.0; \
	${LN} -s libfirestring.so.0 libfirestring.so

.include <bsd.port.mk>
