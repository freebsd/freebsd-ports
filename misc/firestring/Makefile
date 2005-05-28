# New ports collection makefile for:	firestring
# Date created:		Mon 13 May 14:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	firestring
PORTVERSION=	0.9.12
CATEGORIES=	misc net devel
MASTER_SITES=	http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	A library to make string handling easier in C

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

USE_GCC=	3.4+

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=	firestring_chomp.3 firestring_chug.3 firestring_concat.3 \
	firestring_conf_add.3 firestring_conf_delete.3 \
	firestring_conf_find.3 firestring_conf_find_next.3 \
	firestring_conf_free.3 firestring_conf_parse.3 \
	firestring_conf_parse_next.3 firestring_estr_0.3 \
	firestring_estr_aestrcat.3 firestring_estr_aestrcpy.3 \
	firestring_estr_alloc.3 firestring_estr_areplace.3 \
	firestring_estr_astrcat.3 firestring_estr_astrcpy.3 \
	firestring_estr_base64_decode.3 firestring_estr_base64_encode.3 \
	firestring_estr_chomp.3 firestring_estr_chug.3 \
	firestring_estr_eends.3 firestring_estr_ends.3 \
	firestring_estr_estarts.3 firestring_estr_estrcasecmp.3 \
	firestring_estr_estrcat.3 firestring_estr_estrcmp.3 \
	firestring_estr_estrcpy.3 firestring_estr_estristr.3 \
	firestring_estr_estrncasecmp.3 firestring_estr_estrstr.3 \
	firestring_estr_expand.3 firestring_estr_free.3 \
	firestring_estr_ip_chug.3 firestring_estr_ip_trim.3 \
	firestring_estr_munch.3 firestring_estr_read.3 \
	firestring_estr_replace.3 firestring_estr_sprintf.3 \
	firestring_estr_sprintfe.3 firestring_estr_starts.3 \
	firestring_estr_strcasecmp.3 firestring_estr_strcat.3 \
	firestring_estr_strchr.3 firestring_estr_strcmp.3 \
	firestring_estr_strcpy.3 firestring_estr_stristr.3 \
	firestring_estr_strstr.3 firestring_estr_tolower.3 \
	firestring_estr_toupper.3 firestring_estr_trim.3 \
	firestring_estr_vsprintf.3 firestring_estr_vsprintfe.3 \
	firestring_estr_xml_decode.3 firestring_estr_xml_encode.3 \
	firestring_fprintf.3 firestring_fprintfe.3 \
	firestring_hextoi.3 firestring_malloc.3 firestring_printf.3 \
	firestring_printfe.3 firestring_realloc.3 \
	firestring_set_error_handler.3 firestring_snprintf.3 \
	firestring_strcasecmp.3 firestring_strdup.3 \
	firestring_strncasecmp.3 firestring_strncat.3 \
	firestring_strncpy.3 firestring_trim.3 \
	firestring_vfprintf.3 firestring_vfprintfe.3 \
	libfirestring.3

pre-configure:
	@-${RM} ${WRKSRC}/firemake/*.orig

.include <bsd.port.post.mk>
