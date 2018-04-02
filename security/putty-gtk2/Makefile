# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-gtk2

OPTIONS_SLAVE=		GTK2
OPTIONS_EXCLUDE=	GTK3

CONFLICTS_INSTALL=	pssh-[0-9]* putty-[0-9]* putty-nogtk-[0-9]*

MASTERDIR=		${.CURDIR}/../../security/putty

.include "${MASTERDIR}/Makefile"
