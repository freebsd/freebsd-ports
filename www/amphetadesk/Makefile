# Ports collection Makefile for:	AmphetaDesk
# Date created:				8 April 2004
# Whom:					kstailey
#
# $FreeBSD$
#

PORTNAME=	amphetadesk
PORTVERSION=	0.93.1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-v${PORTVERSION}

MAINTAINER=	kstailey@yahoo.com
COMMENT=	RSS client that serves HTTP to your local web browser

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

post-extract:
	@ ${INSTALL_SCRIPT} ${FILESDIR}/AmphetaDesk ${WRKSRC}

post-patch:
	@ ${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 -x ${REINPLACE_CMD} -E \
		-e 's|/usr/bin/perl|${PERL}|'
	@ ${REINPLACE_CMD} -E -e 's|%%ADESK%%|${ADESK}|' ${WRKSRC}/AmphetaDesk

# fit in 80 colums via macro reductions
# srcs
AWRK=		${WRKSRC}/lib/AmphetaDesk
TWRK=		${WRKSRC}/lib/Text
DWRK=		${WRKSRC}/docs
IWRK=		${DWRK}/images
DATA=		${WRKSRC}/data
LIST=		${DATA}/lists/services-channels-recent.xml
TMPL=		${WRKSRC}/templates
DEFL=		${TMPL}/default
GUI=		${DEFL}/gui
DIMG		=${DEFL}/images

# dests
ADESK_DOC=	${PREFIX}/share/doc/AmphetaDesk
ADESK_IMG=	${ADESK_DOC}/images
ADESK=		${SITE_PERL}/AmphetaDesk
ADESK_OS=	${ADESK}/OS
ADESK_DATA=	${ADESK}/data
ADESK_LIST=	${ADESK_DATA}/lists
ADESK_TMPL=	${ADESK}/templates
ADESK_DEFL=	${ADESK_TMPL}/default
ADESK_GUI=	${ADESK_DEFL}/gui
ADESK_DIMG=	${ADESK_DEFL}/images

do-install:
	@ ${MKDIR} ${ADESK}
	@ ${MKDIR} ${ADESK_OS}
	@ ${MKDIR} ${ADESK_DOC}
	@ ${MKDIR} ${ADESK_IMG}
	@ ${MKDIR} ${ADESK_LIST}
	@ ${MKDIR} ${ADESK_TMPL}
	@ ${MKDIR} ${ADESK_DEFL}
	@ ${MKDIR} ${ADESK_GUI}
	@ ${MKDIR} ${ADESK_DIMG}
	@ ${INSTALL_SCRIPT} ${WRKSRC}/AmphetaDesk	   ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/AmphetaDesk.pl	   ${ADESK}
	@ ${INSTALL_DATA} ${WRKSRC}/lib/AmphetaDesk.pm 	   ${SITE_PERL}
	@ ${INSTALL_DATA} ${WRKSRC}/lib/README.txt     	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/Channels.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/ChannelsList.pm      	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/MyChannels.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/Settings.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/Templates.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/Utilities.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/Versioning.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/WWW.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/WebServer.pm	       	   ${ADESK}
	@ ${INSTALL_DATA} ${AWRK}/OS/Linux.pm	       	   ${ADESK_OS}
	@ ${INSTALL_DATA} ${DWRK}/CHANGELOG	       	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/LICENSE	       	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/README.txt	       	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/TODO		       	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/build.html	       	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/files_and_dirs.html  	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/finding_more.html	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/give_thanks.html	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/history.html		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/index.html		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/kudos.html		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/naming.html		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/news.html		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/news.xml		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/screenshots.html	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/skinning.html		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/version.txt		   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/website_integration.html ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/whats_new.html	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/xml_my_services.html	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/xml_my_settings.html	   ${ADESK_DOC}
	@ ${INSTALL_DATA} ${DWRK}/xml_services_lists.html  ${ADESK_DOC}
	@ ${INSTALL_DATA} ${IWRK}/bkgrnd.gif      	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/fyuze.gif       	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/globe.gif       	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/livejournal.jpg 	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/logo-88x31.gif  	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/logo.gif        	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/mailarchive.gif 	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/meerkat.jpg     	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/moreover.gif    	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/network54.gif   	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/newsisfree.gif  	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/nwfusion.gif    	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/quicktopic.gif  	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/racingnews.jpg  	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/sherch.jpg      	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/snewp.jpg       	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/syndic8.gif     	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/xml.gif	  	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/xml_pill.gif    	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/xml_radio.gif   	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${IWRK}/yahoogroups.gif 	   ${ADESK_IMG}
	@ ${INSTALL_DATA} ${DATA}/README.txt		   ${ADESK_DATA}
	@ ${INSTALL_DATA} ${LIST}			   ${ADESK_LIST}
	@ ${INSTALL_DATA} ${TMPL}/README.txt		   ${ADESK_TMPL}
	@ ${INSTALL_DATA} ${DEFL}/add_a_channel.html	   ${ADESK_DEFL}
	@ ${INSTALL_DATA} ${DEFL}/index.html		   ${ADESK_DEFL}
	@ ${INSTALL_DATA} ${DEFL}/my_channels.html	   ${ADESK_DEFL}
	@ ${INSTALL_DATA} ${DEFL}/my_settings.html	   ${ADESK_DEFL}
	@ ${INSTALL_DATA} ${DEFL}/popup.html		   ${ADESK_DEFL}
	@ ${INSTALL_DATA} ${DEFL}/tpl_footer.html	   ${ADESK_DEFL}
	@ ${INSTALL_DATA} ${DEFL}/tpl_header.html	   ${ADESK_DEFL}
	@ ${INSTALL_DATA} ${GUI}/linux_icon.png		   ${ADESK_GUI}
	@ ${INSTALL_DATA} ${GUI}/linux_logo.png		   ${ADESK_GUI}
	@ ${INSTALL_DATA} ${DIMG}/bkgrnd.gif   		   ${ADESK_DIMG}
	@ ${INSTALL_DATA} ${DIMG}/delete.gif   		   ${ADESK_DIMG}
	@ ${INSTALL_DATA} ${DIMG}/email.gif    		   ${ADESK_DIMG}
	@ ${INSTALL_DATA} ${DIMG}/globe.gif    		   ${ADESK_DIMG}
	@ ${INSTALL_DATA} ${DIMG}/logo.gif		   ${ADESK_DIMG}
	@ ${INSTALL_DATA} ${DIMG}/xml.gif		   ${ADESK_DIMG}
	@ ${INSTALL_DATA} ${DIMG}/xml_radio.gif		   ${ADESK_DIMG}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
