# New ports collection makefile for:	bb
# Version required:     1.04H
# Date created:         So  17 Nov 1996 16:59:23 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.30 1998/10/10 04:11:25 steve Exp $
#

DISTNAME=	bb-1.2a
CATEGORIES=	net
MASTER_SITES=	http://maclawran.ca/~sean/bb-dnld/ \
		http://freefall.freebsd.org/~andreas/download/

MAINTAINER=	andreas@FreeBSD.ORG

# The FreeBSD Ports Team has permission to include this in our CDROM
# from the author, but others who wish to do likewise will have to
# contact Sean MacGuire <sean@iti.qc.ca>.

WRKSRC=		${WRKDIR}/bb

pre-configure:
	@echo "==================================================="
	@echo "You need to install a WWW Server to use this port"
	@echo "For example: - apache13 or "
	@echo "             - apache13-modssl
	@echo "port."
	@echo "==================================================="

post-configure:
	( cd ${WRKSRC}/doc; ${SH} bbconfig freebsd )
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	cd ${WRKDIR}; tar cf - bb | ( cd ${PREFIX}; tar xpf - )
	@${LN} -fs ${PREFIX}/bb/www ${PREFIX}/share/apache/htdocs/bb
	@${LN} -fs bb.html ${PREFIX}/bb/www/index.html
	mv -f ${PREFIX}/bb/doc ${PREFIX}/share/doc/bb
	@echo ""
	@echo "================================================================"
	@echo "==== Configuration Notes:                                    ==="
	@echo "================================================================"
	@echo ""
	@echo "a) your hosts 'full qualified domain name' and IP-address"
	@echo "b) 'watched' hosts 'full qualified domain name' and IP-address"
	@echo "go here -> ${PREFIX}/bb/etc/bb-hosts"
	@echo ""
	@echo "c) configure -> ${PREFIX}/bb/etc/bbdef.sh"
	@echo "d) configure -> ${PREFIX}/bb/etc/bbinc.sh"
	@echo ""
	@echo "e) You need to have a running WWW server (apache)"
	@echo "f) You need kermit or qpage for pager functionality"
	@echo ""
	@echo "After that, you can startup the big brother service by typing"
	@echo "        ${PREFIX}/bb/runbb.sh &"
	@echo ""
	@echo "and watching your systems status by viewing this URL with"
	@echo "Netscape or another WWW browser"
	@echo "        http://localhost/bb"

.include <bsd.port.mk>
