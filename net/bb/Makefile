# New ports collection makefile for:	bb
# Version required:     1.04H
# Date created:         So  17 Nov 1996 16:59:23 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.31 1999/06/26 12:01:23 andreas Exp $
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
	@cd ${WRKDIR} && find . -name "*.orig" | xargs ${RM}
	@cd ${WRKDIR}; tar --exclude 'src' -c -f - bb \
		| ( cd ${PREFIX}; tar xpf - )
	@${LN} -fs ${PREFIX}/bb/www ${PREFIX}/share/apache/htdocs/bb
	@${LN} -fs bb.html ${PREFIX}/bb/www/index.html
	@${LN} -fs ${PREFIX}/bb/web/bb-ack.sh ${PREFIX}/share/apache/cgi-bin
	@mv -f ${PREFIX}/bb/doc/bbclient ${PREFIX}/bb/bin
	@mv -f ${PREFIX}/bb/doc/bbconfig ${PREFIX}/bb/bin
	@mv -f ${PREFIX}/bb/doc ${PREFIX}/share/doc/bb
	@${MKDIR} ${PREFIX}/share/bb/bbclients
	@${TOUCH} ${PREFIX}/share/bb/bbclients/.keep_me
	@${RM} ${PREFIX}/bb/KNOWN.BUGS
	@${RM} ${PREFIX}/bb/README
	@${RM} ${PREFIX}/bb/README.CHANGES
	@${RM} ${PREFIX}/bb/README.INSTALL
	@echo ""
	@echo "================================================================"
	@echo "==== Configuration Notes:                                    ==="
	@echo "================================================================"
	@echo ""
	@echo "a) your hosts 'full qualified domain name' and IP-address"
	@echo "b) 'watched' hosts 'full qualified domain name' and IP-address"
	@echo "go here -> ${PREFIX}/bb/etc/bb-hosts"
	@echo "c) configure -> ${PREFIX}/bb/etc/bbdef.sh"
	@echo "d) configure -> ${PREFIX}/bb/etc/bbinc.sh"
	@echo "e) You need to have a running WWW server (apache)"
	@echo "f) You need kermit or qpage for pager functionality"
	@echo "After that, you can startup the big brother service by typing"
	@echo "        ${PREFIX}/bb/runbb.sh &"
	@echo "and watching your systems status by viewing this URL with"
	@echo "Netscape or another WWW browser"
	@echo "        http://localhost/bb"

.include <bsd.port.mk>
