# New ports collection makefile for:	dnews
# Version required:     47k
# Date created:		Thu May 29 17:16:36 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.11 1998/12/23 01:22:40 steve Exp $
#

DISTNAME=	dnews47k_freebsd
PKGNAME=	dnews-4.7k
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.netwinsite.com/pub/netwinsite/dnews/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.ORG

Y2K=		http://netwinsite.com/dnews_y2k.htm

WRKSRC=         ${WRKDIR}/dnews
NO_CDROM=	"no answer yet, if we are allowed to put it onto CDROM"
RESTRICTED=	"only free for non-profit organisations"
NO_PACKAGE=	"${RESTRICTED}"
IS_INTERACTIVE=	yes

NO_BUILD=	yes

post-configure:
	@${PERL} -pi -e "s|df -k|/bin/df -k|" ${WRKSRC}/dnews.conf
	@${PERL} -pi -e "s|lib/sendmail|sbin/sendmail|" ${WRKSRC}/dnews.conf

do-install:
	@( cd ${WRKSRC}; ./dnews_setup )
	@${ECHO_MSG} "Installing dnews startup script as ${PREFIX}/etc/rc.d/dnews.sh"
	@${INSTALL_SCRIPT} ${FILESDIR}/dnews.sh ${PREFIX}/etc/rc.d/dnews.sh
	@${INSTALL_DATA} ${FILESDIR}/faq.html ${PREFIX}/dnews/faq.html

post-install:
	@${MV} /etc/dnews.conf ${PREFIX}/etc/dnews.conf
	@${LN} -s ${PREFIX}/etc/dnews.conf /etc/dnews.conf
	@${ECHO_MSG} "*** DNEWS is NOT free, please read the LICENSE file:"
	@${ECHO_MSG} "***	${PREFIX}/dnews/license.txt"
	@${ECHO_MSG} "*** The main configuration file is:"
	@${ECHO_MSG} "***	${PREFIX}/etc/dnews.conf"

.include <bsd.port.mk>
