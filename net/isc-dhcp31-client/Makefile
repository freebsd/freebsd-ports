# ex:ts=8
# Ports collection makefile for:    dhcp
# Date created:         28 April 2003
# Whom:                 cyrille.lefevre@laposte.net
#
# $FreeBSD$
#

COMMENT=	The ISC Dynamic Host Configuration Protocol client

FORBIDDEN=	Vulnerable since 2011-04-10, http://portaudit.freebsd.org/7e69f00d-632a-11e0-9f3a-001d092480a4.html
EXPIRATION_DATE=	2011-10-14

# Local variables
#

SUBSYS=		client

# Local overrides
#

MASTERDIR=	${.CURDIR}/../isc-dhcp31-server

.include "${MASTERDIR}/Makefile"
