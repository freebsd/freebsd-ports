# New ports collection makefile for:	pbm2ppa
# Date created:		18 November 1998
# Whom:			smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	pbm2ppa 
PORTVERSION=	0.8.6 
CATEGORIES=	print
MASTER_SITES=	http://www.httptech.com/ppa/files/
DISTNAME=	ppa-0.8.6

MAINTAINER=	smace@freebsd.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5 \
		enscript:${PORTSDIR}/print/enscript-letter

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes

HPMODEL?=	720
ALL_TARGET=	${HPMODEL}

pre-configure:
.if ${HPMODEL} != 720 && ${HPMODEL} != 820 && ${HPMODEL} != 1000
	@${ECHO} "HPMODEL is invalid: ${HPMODEL}."
	@${ECHO} "You must specify the model of your printer:"
	@${ECHO} "720 -- HP720 family (HP 722C, etc.)"
	@${ECHO} "820 -- HP820 family"
	@${ECHO} "1000 -- HP820 family"
	@${FALSE}
.endif
.if !defined(PAPERSIZE)
	@${ECHO}
	@${ECHO} "No PAPERSIZE environment variable found, will default to enscript-letter"
	@${ECHO}
.endif

do-install:
	${SED} s#CHANGETHIS#${PREFIX}# < ${FILESDIR}/ppafilter.SH > ${WRKSRC}/ppafilter
	${SED} s#CHANGETHIS#${PREFIX}# < ${FILESDIR}/asciippafilter.SH > ${WRKSRC}/asciippafilter
	cd ${WRKSRC} && \
		(${INSTALL_PROGRAM} pbm2ppa pbmtpg \
			${PREFIX}/bin; \
		${INSTALL_DATA} pbm2ppa.conf.hp${HPMODEL} \
			${PREFIX}/etc/pbm2ppa.conf; \
		${INSTALL_SCRIPT} ppafilter asciippafilter \
			${PREFIX}/bin )

post-install:
	@${ECHO}
	@${ECHO} "To configure your printcap to print either ascii"
	@${ECHO} "or Postscript files, add the following lines to your"
	@${ECHO} "/etc/printcap file"
	@${ECHO}
	@${ECHO} "	lp|ascii|unix:\\"
	@${ECHO} "	        :lp=/dev/lpt0:\\"
	@${ECHO} "	        :sd=/var/spool/lpd:\\"
	@${ECHO} "	        :if=/usr/local/bin/asciippafilter:\\"
	@${ECHO} "	        :mx#0:\\"
	@${ECHO} "	        :sh:"
	@${ECHO}
	@${ECHO} "	ps:\\"
	@${ECHO} "	        :lp=/dev/lpt0:\\"
	@${ECHO} "	        :sd=/var/spool/ps:\\"
	@${ECHO} "	        :if=/usr/local/bin/ppafilter:\\"
	@${ECHO} "	        :mx#0:\\"
	@${ECHO} "	        :sh:"
	@${ECHO}
	@${ECHO} "Please be sure that you install the proper flavor of"
	@${ECHO} "enscript, either A4 or Letter, by setting the PAPERSIZE"
	@${ECHO} "environment variable."
	@${ECHO}

.include <bsd.port.mk>
