# New ports collection makefile for:	libieee1284
# Date created:		2004-12-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libieee1284
PORTVERSION=	0.2.8
CATEGORIES=	sysutils
MASTER_SITES=	http://cyberelk.net/tim/data/libieee1284/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IEEE1284 communications library

USE_BZIP2=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386

PORTDOCS=	README.FreeBSD README
MAN3=	libieee1284.3 parport.3 parport_list.3 ieee1284_find_ports.3 \
	ieee1284_free_ports.3 ieee1284_get_deviceid.3 ieee1284_open.3 \
	ieee1284_close.3 ieee1284_ref.3 ieee1284_unref.3 ieee1284_claim.3 \
	ieee1284_release.3 ieee1284_read_data.3 ieee1284_write_data.3 \
	ieee1284_data_dir.3 ieee1284_wait_data.3 ieee1284_read_status.3 \
	ieee1284_wait_status.3 ieee1284_read_control.3 ieee1284_write_control.3 \
	ieee1284_frob_control.3 ieee1284_do_nack_handshake.3 ieee1284_negotiate.3 \
	ieee1284_terminate.3 ieee1284_ecp_fwd_to_rev.3 ieee1284_ecp_rev_to_fwd.3 \
	ieee1284_nibble_read.3 ieee1284_compat_write.3 ieee1284_byte_read.3 \
	ieee1284_epp_read_data.3 ieee1284_epp_write_data.3 ieee1284_epp_read_addr.3 \
	ieee1284_epp_write_addr.3 ieee1284_ecp_read_data.3 ieee1284_ecp_write_data.3 \
	ieee1284_ecp_read_addr.3 ieee1284_ecp_write_addr.3 ieee1284_get_irq_fd.3 \
	ieee1284_set_timeout.3

PLIST_FILES=	bin/libieee1284_test \
		include/ieee1284.h \
		lib/libieee1284.a \
		lib/libieee1284.so \
		lib/libieee1284.so.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
