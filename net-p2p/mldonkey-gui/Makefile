# Created by: Holger Lamm <holger@e-gitt.net>
# $FreeBSD$

# build only the GUI
WITHOUT_CORE=	yes
# unbreak index build with a common variable
.undef WITHOUT_GUI

COMMENT=	OCAML/GTK GUI for the MLdonkey peer-to-peer network client

MASTERDIR=	${.CURDIR}/../mldonkey

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
