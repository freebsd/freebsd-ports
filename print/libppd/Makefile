# New ports collection makefile for:    libppd
# Date created:         22 Apr 2005 17:00:00 CEST
# Whom:                 e-masson@kisoft-services.com
#
# $FreeBSD$
#

PORTNAME=	libppd
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	SF/lpr/${PORTNAME}/${PORTVERSION}

MAINTAINER=	emss@free.fr
COMMENT=	A library providing routines for ppd files

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	Yes
USE_GNOME=	glib12
MAKE_JOBS_UNSAFE=	yes

MAN1=		ppdfilt.1
MAN3=           ppd_check_option_is_marked.3 ppd_emit_to_file.3 \
		ppd_file_free.3 ppd_file_new.3 ppd_find_choice.3 \
		ppd_get_num_conflicts.3 ppd_get_page_length.3

.include <bsd.port.mk>
