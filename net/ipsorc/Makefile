# New ports collection makefile for:    ipsorc
# Date created:                         02 December, 2001
# Whom:                                 Nicolas.Jombart@hsc-labs.com
#
# $FreeBSD$
#

PORTNAME=	ipsorc
PORTVERSION=	1.7.5
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.informony.com/ipsorc/ \
		http://sorcerer.mirrors.pair.com/sources/ipsorcery/${PORTVERSION}/ \
		http://www.l0t3k.net/tools/PacketGenerator/

MAINTAINER=	ecu@ipv42.net
COMMENT=	A tool to create and send IP packets with a graphical GTK front-end

USE_GNOME=	gtk12
USE_BZIP2=	yes

post-patch:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	@${SED} s,gtk-config,${GTK_CONFIG}, < ${WRKSRC}/Makefile.old \
	        > ${WRKSRC}/Makefile
	@${RM} ${WRKSRC}/Makefile.old

do-install:
.for file in ipmagic magic
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README HOWTO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
