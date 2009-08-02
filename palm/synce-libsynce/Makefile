# New ports collection makefile for:   synce-libsynce
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	libsynce
PORTVERSION=	0.13
CATEGORIES=	palm
MASTER_SITES=	SF/synce
PKGNAMEPREFIX=	synce-

MAINTAINER=	webmaster@kibab.com
COMMENT=	Library to support communication with WinCE devices

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		hal.1:${PORTSDIR}/sysutils/hal

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_ICONV=	yes
USE_GNOME=	gnomehack gnometarget
CONFIGURE_ARGS+=	--with-libiconv-prefix="${LOCALBASE}" \
			--enable-dccm-file-support=no \
			--enable-hal-support=yes \
			--enable-odccm-support=no

MAN3=		synce_info_new.3 wstrlen.3 wstrcpy.3 wstrdup.3 \
		synce_get_directory.3 synce_get_connection_filename.3 \
		synce_strerror.3 wstr_to_ascii.3 time_fields_from_filetime.3 \
		date_from_tm.3 synce_error.3 synce_info_destroy.3 \
		synce_get_subdirectory.3 synce_get_script_directory.3 \
		synce_set_connection_filename.3 wstr_to_current.3 \
		synce_set_default_connection_filename.3 wstr_to_utf8.3 \
		wstr_from_ascii.3 wstr_from_utf8.3 wstr_from_current.3 \
		wstr_free_string.3 wstr_append.3 wstr_equal.3 \
		time_fields_to_filetime.3 date_to_tm.3 synce_warning.3 \
		synce_info.3 synce_debug.3 synce_trace.3 \
		synce_warning_unless.3 synce_log_set_level.3 \
		synce_log_use_syslog.3
MAN7=		synce.7

USE_LDCONFIG=	yes

.include <bsd.port.mk>
