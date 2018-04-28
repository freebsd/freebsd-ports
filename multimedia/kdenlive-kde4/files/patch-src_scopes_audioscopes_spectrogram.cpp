Fix ambiguity of abs().

[7%] Building CXX object src/CMakeFiles/kdenlive.dir/scopes/audioscopes/spectrogram.cpp.o
/tmp/usr/ports/multimedia/kdenlive/work/kdenlive-16.04.3/src/scopes/audioscopes/spectrogram.cpp:276:77: error: call to 'abs' is ambiguous
            hideText = m_aTrackMouse->isChecked() && m_mouseWithinWidget && abs(x-(leftDist + mouseX + 30)) < (int) minDistX
                                                                            ^~~
/usr/include/stdlib.h:83:6: note: candidate function
int      abs(int) __pure2;
         ^
/usr/include/c++/v1/stdlib.h:115:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long      abs(     long __x) _NOEXCEPT {return  labs(__x);}
                                           ^
/usr/include/c++/v1/stdlib.h:117:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long long abs(long long __x) _NOEXCEPT {return llabs(__x);}
                                           ^
[...]

--- src/scopes/audioscopes/spectrogram.cpp.orig	2016-07-12 21:44:03 UTC
+++ src/scopes/audioscopes/spectrogram.cpp
@@ -245,7 +245,7 @@ QImage Spectrogram::renderHUD(uint)
                 x = leftDist + (m_innerScopeRect.width()-1) * ((float)hz)/m_freqMax;

                 // Hide text if it would overlap with the text drawn at the mouse position
-                hideText = m_aTrackMouse->isChecked() && m_mouseWithinWidget && abs(x-(leftDist + mouseX + 20)) < (int) minDistX + 16
+                hideText = m_aTrackMouse->isChecked() && m_mouseWithinWidget && abs((int)(x-(leftDist + mouseX + 20))) < (int) minDistX + 16
                         && mouseX < m_innerScopeRect.width() && mouseX >= 0;

                 if (x <= rightBorder) {
@@ -273,7 +273,7 @@ QImage Spectrogram::renderHUD(uint)
             }
             // Draw the line at the very right (maximum frequency)
             x = leftDist + m_innerScopeRect.width()-1;
-            hideText = m_aTrackMouse->isChecked() && m_mouseWithinWidget && abs(x-(leftDist + mouseX + 30)) < (int) minDistX
+            hideText = m_aTrackMouse->isChecked() && m_mouseWithinWidget && abs((int)(x-(leftDist + mouseX + 30))) < (int) minDistX
                     && mouseX < m_innerScopeRect.width() && mouseX >= 0;
             davinci.drawLine(x, topDist, x, topDist + m_innerScopeRect.height()+6);
             if (!hideText) {
