# New ports collection makefile for:	bb
# Version required:     1.04H
# Date created:         So  17 Nov 1996 16:59:23 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	bb-1.2a
CATEGORIES=	net
MASTER_SITES=	http://maclawran.ca/~sean/bb-dnld/ \
		http://freefall.freebsd.org/~andreas/download/

MAINTAINER=	billf@FreeBSD.org

# The FreeBSD Ports Team has permission to include this in our CDROM
# from the author, but others who wish to do likewise will have to
# contact Sean MacGuire <sean@iti.qc.ca>.

WRKSRC=		${WRKDIR}/bb

pre-configure:
	@${ECHO_MSG} "==================================================="
	@${ECHO_MSG} "You need to install a WWW Server to use this port"
	@${ECHO_MSG} "For example: - apache13 or "
	@${ECHO_MSG} "             - apache13-modssl
	@${ECHO_MSG} "port."
	@${ECHO_MSG} "==================================================="

post-configure:
	( cd ${WRKSRC}/doc; ${SH} bbconfig freebsd )
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@cd ${WRKDIR} && find . -name "*.orig" | xargs ${RM}
	@cd ${WRKDIR}; tar --exclude 'src' -c -f - bb \
		| ( cd ${PREFIX}; tar xpf - )
	@${RM} -f ${PREFIX}/share/doc/apache/manual/bb
	@${MKDIR} ${PREFIX}/share/doc/apache/manual
	@${LN} -fs ${PREFIX}/bb/www ${PREFIX}/share/doc/apache/manual/bb
	@${LN} -fs bb.html ${PREFIX}/bb/www/index.html
	@${MKDIR} ${PREFIX}/share/apache/cgi-bin
	@${LN} -fs ${PREFIX}/bb/web/bb-ack.sh ${PREFIX}/share/apache/cgi-bin
	@${MV} -f ${PREFIX}/bb/doc/bbclient ${PREFIX}/bb/bin
	@${MV} -f ${PREFIX}/bb/doc/bbconfig ${PREFIX}/bb/bin
	@${MV} -f ${PREFIX}/bb/doc ${PREFIX}/share/doc/bb
	@${MKDIR} ${PREFIX}/share/bb/bbclients
	@${TOUCH} ${PREFIX}/share/bb/bbclients/.keep_me
	@${RM} ${PREFIX}/bb/KNOWN.BUGS
	@${RM} ${PREFIX}/bb/README
	@${RM} ${PREFIX}/bb/README.CHANGES
	@${RM} ${PREFIX}/bb/README.INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
