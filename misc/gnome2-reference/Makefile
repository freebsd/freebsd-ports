# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/misc/gnome2-reference/Makefile,v 1.9 2008/08/23 18:22:59 mezz Exp $

PORTNAME=	gnome2-reference
PORTVERSION=	2.20
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for GNOME 2 programming references

# Please keep this list alphabetically sorted.
# If you add or remove an entry from REF_LIST you must
# run 'make create-ref-list'

REF_LIST=	accessibility/at-spi-reference \
		accessibility/atk-reference \
		databases/libgda2-reference \
		databases/libgda3-reference \
		databases/libgnomedb-reference \
		devel/ORBit2-reference \
		devel/gconf2-reference \
		devel/glib20-reference \
		devel/glibmm-reference \
		devel/gnome-vfs-reference \
		devel/libbonobo-reference \
		devel/libglade2-reference \
		devel/libsoup-reference \
		graphics/cairo-reference \
		graphics/libgnomecanvas-reference \
		net/linc-reference \
		print/libgnomeprint-reference \
		textproc/gtkspell-reference \
		textproc/libxml2-reference \
		textproc/libxslt-reference \
		x11/gnome-desktop-reference \
		x11/gnome-panel-reference \
		x11/libgnome-reference \
		x11-fonts/fontconfig-reference \
		x11-toolkits/gal2-reference \
		x11-toolkits/gtk20-reference \
		x11-toolkits/gtkmm20-reference \
		x11-toolkits/gtkmm24-reference \
		x11-toolkits/gtksourceview-reference \
		x11-toolkits/libbonoboui-reference \
		x11-toolkits/libgnomeui-reference \
		x11-toolkits/libwnck-reference \
		x11-toolkits/pango-reference \
		x11-toolkits/vte-reference

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.MAKE.FreeBSD_UL= yes

REF_LIST_INC=	${.CURDIR}/Makefile.inc
.include "${REF_LIST_INC}"

.for ref in ${_PORT_REF_LIST:C/^([^:]+).*/\1/}
OPTIONS_DEFINE+=	${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//:S/-/_/:U}
OPTIONS_DEFAULT+=	${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//:S/-/_/:U}
${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//:S/-/_/:U}_DESC=	Install ${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//} programing reference
.endfor

.include <bsd.port.options.mk>

.for ref in ${_PORT_REF_LIST}
.if ${PORT_OPTIONS:M${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//:S/-/_/:U:C/^([^:]+).*/\1/}}
RUN_DEPENDS+=	${ref:C|^[^:]+:([^:]+).*|\1|:C|^[^/]+/([^/]+).*|\1|}>0:${PORTSDIR}/${ref:C/^([^:]+).*/\1/}
.endif
.endfor

create-ref-list:
	${CP} ${REF_LIST_INC} ${REF_LIST_INC}.bak
	${ECHO_CMD} "_PORT_REF_LIST= \\" > ${REF_LIST_INC}
.for port in ${REF_LIST}
	(cd ${PORTSDIR}/${port} && ${ECHO_CMD} "${port}:`${MAKE} -V PKGBASE` \\" >> ${REF_LIST_INC})
.endfor

.include <bsd.port.mk>
