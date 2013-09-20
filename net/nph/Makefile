# Created by: Jim Pirzyk <pirzyk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nph
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.feep.net/pub/software/nph/

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	New PH Client and API Library

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-encap --disable-epkg-install

MANCOMPRESSED=	no

MAN1=	nph.1
MAN3=	ph_add.3 \
		ph_advertised_email.3 \
		ph_advertised_www.3 \
		ph_change.3 \
		ph_close.3 \
		ph_decode_field_attributes.3 \
		ph_delete.3 \
		ph_email_resolve.3 \
		ph_encode_selector.3 \
		ph_external.3 \
		ph_fieldinfo_iterate.3 \
		ph_free_entries.3 \
		ph_free_selectors.3 \
		ph_free_serverlist.3 \
		ph_get_fieldinfo.3 \
		ph_get_option.3 \
		ph_get_siteinfo.3 \
		ph_id.3 \
		ph_login.3 \
		ph_logout.3 \
		ph_open.3 \
		ph_option_iterate.3 \
		ph_passwd.3 \
		ph_query.3 \
		ph_retrieve_fieldinfo.3 \
		ph_retrieve_options.3 \
		ph_retrieve_siteinfo.3 \
		ph_rfd.3 \
		ph_serverlist_add.3 \
		ph_serverlist_iterate.3 \
		ph_serverlist_merge.3 \
		ph_set_hookdata.3 \
		ph_set_option.3 \
		ph_set_recvhook.3 \
		ph_set_sendhook.3 \
		ph_siteinfo_iterate.3 \
		ph_status.3 \
		ph_suser.3 \
		ph_wfd.3 \
		ph_whoami.3 \
		ph_www_resolve.3

NO_STAGE=	yes
do-install:
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-recurse)

	-@${MKDIR} ${PREFIX}/etc
	@${CP} ${WRKSRC}/nphrc ${PREFIX}/etc/nphrc.sample
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-clean:
	@${RM} -f ${PREFIX}/etc/ph_server

.include <bsd.port.mk>
