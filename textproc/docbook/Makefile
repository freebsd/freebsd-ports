# New ports collection makefile for:   docbook
# Date created:        7 April 1999
# Whom:                Nik Clayton <nik@freebsd.org>
#
# Based heavily on work by jfieber
#
# $FreeBSD$
#

PORTNAME=	docbook
PORTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nik@freebsd.org
COMMENT=	Meta-port for the different versions of the DocBook DTD

RUN_DEPENDS=	${PREFIX}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${PREFIX}/share/sgml/docbook/2.4.1:${PORTSDIR}/textproc/docbook-241 \
		${PREFIX}/share/sgml/docbook/3.0:${PORTSDIR}/textproc/docbook-300 \
		${PREFIX}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310 \
		${PREFIX}/share/sgml/docbook/4.0:${PORTSDIR}/textproc/docbook-400 \
		${PREFIX}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-410 \
		${PREFIX}/share/xml/docbook/4.2:${PORTSDIR}/textproc/docbook-xml

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:
	@${INSTALL_DATA} ${FILESDIR}/catalog ${PREFIX}/share/sgml/docbook/catalog

.include <bsd.port.mk>
