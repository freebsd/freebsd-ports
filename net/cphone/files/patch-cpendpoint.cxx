*** cpendpoint.cxx.orig	Fri May 10 01:53:47 2002
--- cpendpoint.cxx	Wed Nov 27 09:18:30 2002
*************** void CpEndPoint::DeleteVideoDisplay()
*** 151,158 ****
  
  BOOL CpEndPoint::InitialiseVoipSettings()
  {
!   rtpIpPortBase = 49604;
!   rtpIpPortMax  = 65534;
  
    if (!connectOpts.userName.IsEmpty()) 
      SetLocalUserName(connectOpts.userName);
--- 151,157 ----
  
  BOOL CpEndPoint::InitialiseVoipSettings()
  {
!   SetRtpIpPorts(49604, 65534); /* PortBase, PortMax*/
  
    if (!connectOpts.userName.IsEmpty()) 
      SetLocalUserName(connectOpts.userName);
