# Ports collection makefile for:	click
# Date created:        3 Nov 2001
# Whom:                gnn
#
# $FreeBSD$
#

PORTNAME=	click
PORTVERSION=	1.4.3
CATEGORIES=	net
MASTER_SITES=	http://www.pdos.lcs.mit.edu/click/

MAINTAINER=	gnn@neville-neil.com
COMMENT=	The Click Modular Router

USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-linuxmodule
USE_GMAKE=	yes

MANCOMPRESSED=	no
INFO=	click
MAN1=	click.1 click-align.1 click-combine.1 click-devirtualize.1 \
	click-fastclassifier.1 click-flatten.1 click-install.1 \
	click-mkmindriver.1 click-pretty.1 click-uncombine.1 click-undead.1 \
	click-uninstall.1 click-xform.1 testie.1
MAN5=	click.5
MAN7=	elementdoc.7
MAN8=	click.o.8
MANN=	FTPPortMapper.n ARPFaker.n ARPQuerier.n ARPResponder.n \
	EnsureEther.n EtherEncap.n EtherMirror.n HostEtherFilter.n \
	CheckICMPHeader.n ICMPError.n ICMPPingResponder.n ICMPPingRewriter.n \
	ICMPRewriter.n CheckIPHeader.n CheckIPHeader2.n \
	DecIPTTL.n FixIPSrc.n FromSocket.n GetIPAddress.n ICMPPingEncap.n \
	ICMPPingSource.n IPAddrRewriter.n IPAddrPairRewriter.n IPClassifier.n \
	IPEncap.n IPFilter.n IPFragmenter.n IPGWOptions.n IPInputCombo.n \
	IPMirror.n IPOutputCombo.n IPPrint.n IPRateMonitor.n IPRewriterPatterns.n \
	KernelTun.n LinearIPLookup.n LinkUnqueue.n LookupIPRoute2.n \
	MarkIPCE.n MarkIPHeader.n Message.n MixedQueue.n NotifierQueue.n \
	PaintSwitch.n PortInfo.n RIPSend.n RandomSwitch.n \
	RoundRobinIPMapper.n SetAnnoByte.n SetIPAddress.n SetIPChecksum.n SetIPDSCP.n \
	SetRandIPAddress.n SetUDPChecksum.n SimpleQueue.n StoreData.n \
	StoreIPAddress.n StripIPHeader.n ToSocket.n UnstripIPHeader.n \
	AddressInfo.n Align.n AlignmentInfo.n AverageCounter.n \
	BandwidthMeter.n BandwidthShaper.n Burster.n BandwidthRatedSplitter.n \
	BandwidthRatedUnqueue.n CheckCRC32.n CheckLength.n CheckPaint.n \
	Classifier.n CompareBlock.n Counter.n DelayShaper.n DelayUnqueue.n \
	Discard.n DiscardNoFree.n DriverManager.n DropBroadcasts.n DRRSched.n \
	Error.n FrontDropQueue.n HashSwitch.n Idle.n \
	InfiniteSource.n Meter.n MSQueue.n Null.n PushNull.n PullNull.n \
	Null1.n Null2.n Null3.n Null4.n Null5.n Null6.n Null7.n Null8.n \
	Paint.n PaintTee.n PokeHandlers.n Print.n PrioSched.n \
	PullSwitch.n Queue.n QuitWatcher.n \
	RandomBitErrors.n RandomSource.n RatedSource.n \
	RatedSplitter.n RatedUnqueue.n RED.n RoundRobinSched.n \
	RoundRobinSwitch.n ScheduleInfo.n SetCRC32.n SetTimestamp.n Shaper.n \
	SourceIPHashMapper.n SortedIPLookup.n \
	SpinlockAcquire.n SpinlockInfo.n SpinlockRelease.n StaticPullSwitch.n \
	StaticSwitch.n StrideSched.n StrideSwitch.n Strip.n Suppressor.n \
	Switch.n Tee.n PullTee.n TimedSink.n TimedSource.n TrieIPLookup.n Unqueue.n \
	Unqueue2.n Unstrip.n CheckTCPHeader.n CheckUDPHeader.n \
	DynamicUDPIPEncap.n IPRewriter.n SetTCPChecksum.n TCPRewriter.n \
	UDPIPEncap.n ChatterSocket.n ControlSocket.n FromDevice.u.n \
	FromDump.n KernelTap.n KernelHandlerProxy.n PrintOld.n \
	ToDevice.u.n ToDump.n elements.n AdaptiveRED.n IPReassembler.n \
	IPRouteTable.n StaticIPLookup.n LinuxIPLookup.n RadixIPLookup.n \
	RandomSample.n SetPacketType.n StripToNetworkHeader.n ProgressBar.n

CONFDIR=	${PREFIX}/etc/click/conf

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha 4.x"
.endif

post-install:
	cd ${PREFIX}/bin && ${STRIP_CMD} click click-align click-check \
	  click-combine click-uncombine click-devirtualize click-fastclassifier \
	  click-flatten click-mkmindriver click-undead click-xform
	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/*.click ${CONFDIR}
	@${MKDIR} ${CONFDIR}/roofnet
	${INSTALL_DATA} ${WRKSRC}/conf/roofnet/etx.click ${CONFDIR}/roofnet
	${INSTALL_DATA} ${WRKSRC}/conf/roofnet/srcr.click ${CONFDIR}/roofnet
	@${MKDIR} ${CONFDIR}/wifi
	${INSTALL_DATA} ${WRKSRC}/conf/wifi/*.click ${CONFDIR}/wifi
	@${ECHO_CMD}
	@${ECHO_CMD} "----------------------------------------------------"
	@${ECHO_CMD} "Install complete, to try it out do the following:"
	@${ECHO_CMD} "cd ${PREFIX}/etc/click/conf"
	@${ECHO_CMD} "click test.click"
	@${ECHO_CMD} "You should see some output.  Now go read the papers and manual."
	@${ECHO_CMD} "----------------------------------------------------"
	@${ECHO_CMD}

.include <bsd.port.post.mk>
