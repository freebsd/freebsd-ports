# $FreeBSD$

BOOKS=		gdk gdk-pixbuf gtk

MAN1=		gdk-pixbuf-csource.1

post-install:
	${INSTALL_MAN} ${MAN1:S|^|${REFERENCE_SRC}/gdk-pixbuf/|} \
		${PREFIX}/man/man1

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
